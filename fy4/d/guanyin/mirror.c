// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�޴�ľ���");
        set("long", @LONG
����ղ�ᣱ�¶��һ�澧Ө���޴�ľ��ӣ������������������鱦��������
��Щ��ֵ���ǵ��鱦��Ҳ�����ڱξ��ӵĹ�ʣ��⾵�ӱ�������Ǵ������ص�ħ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"northup" : __DIR__"bedroom",
  		"southup" : __DIR__"flower2",
	]));
        set("objects", ([
                __DIR__"npc/mirror_soul" : 1,
       	]) );
	set("no_force",1);
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();

}
