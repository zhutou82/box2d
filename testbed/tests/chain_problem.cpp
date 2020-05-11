// MIT License

// Copyright (c) 2019 Erin Catto

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "test.h"

class ChainProblem : public Test
{
public:

    ChainProblem()
    {
        //dump
        {
            b2Vec2 g(0.0f, -10.0f);
            m_world->SetGravity(g);
            b2Body** bodies = (b2Body**)b2Alloc(2 * sizeof(b2Body*));
            b2Joint** joints = (b2Joint**)b2Alloc(0 * sizeof(b2Joint*));
            {
                b2BodyDef bd;
                bd.type = b2BodyType(0);
                bodies[0] = m_world->CreateBody(&bd);

                {
                    b2FixtureDef fd;

                    b2ChainShape shape;
                    b2Vec2 vs[3];
                    vs[0].Set(0.0f, 1.0f);
                    vs[1].Set(0.0f, 0.0f);
                    vs[2].Set(4.0f, 0.0f);
                    shape.CreateChain(vs, 3);
                    shape.m_hasPrevVertex = false;
                    shape.m_hasNextVertex = false;

                    fd.shape = &shape;

                    bodies[0]->CreateFixture(&fd);
                }
            }
            {
                b2BodyDef bd;
                bd.type = b2BodyType(2);
                bd.position.Set(6.033980250358582e-01f, 3.028350114822388e+00f);
                bodies[1] = m_world->CreateBody(&bd);

                {
                    b2FixtureDef fd;
                    fd.friction = 0.2f;
                    fd.density = 10.0f;
                    b2PolygonShape shape;
                    b2Vec2 vs[8];
                    vs[0].Set(0.5f, -3.0f);
                    vs[1].Set(0.5f, 3.0f);
                    vs[2].Set(-0.5f, 3.0f);
                    vs[3].Set(-0.5f, -3.0f);
                    shape.Set(vs, 4);

                    fd.shape = &shape;

                    bodies[1]->CreateFixture(&fd);
                }
            }
            b2Free(joints);
            b2Free(bodies);
            joints = NULL;
            bodies = NULL;
        }
    }

    static Test* Create()
    {
        return new ChainProblem;
    }

};

static int testIndex = RegisterTest("Bugs", "Chain Problem", ChainProblem::Create);
