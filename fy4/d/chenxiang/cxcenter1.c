// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�������ȣ�����ïʢ�������ͤ��Ȼ����Ȼ�γɣ��������Ҷ������˽�֯��
һ�����ν���񹦣����񾭳��������Ϸ�ۻᣬ������������̨�������һ��
�������ϵ��ճ�����֮���������ӻ�����֬���Σ��������С������ǹٸ������ź�
һ��СС�ĳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs1",
  "west" : __DIR__"cxw1",
  "south" : __DIR__"cxs2",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
 

}
