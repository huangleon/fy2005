// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����콾��");
        set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬
�绯��������˵������ʴ���ٷ��ѽ����¶�ŮӢ�۵ĵط������Ǳ���
����Ӣ�۶���Ϊ����֮��һ���������Ƶ������Ͽ��������֣������ơ�
ӣ�������������������
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
]));
        set("coor/x",50);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
