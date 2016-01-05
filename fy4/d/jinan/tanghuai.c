// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ƻ�ͤ");
  set("long",@LONG
ɽ�дӴ��򶫿�ʼ���ͣ�һ����ͤǰ��һ�ô������ݳ��ƴ������������ڴ�
˨��ЪϢ�������Ӵ��ļ����̣����������дУ�������ա�����ɽ�߶��ڴ�Ъ�š�
����·�ڣ���������ɽ����һ��ͨ��������[33m���˹����¡�[32m����һ����ɽ�µ�[33m����[32m��
����ǰ�У�����Ȫ��[33m�����ϡ�[32m��
LONG
  );
  set("exits",([
         "west"  :__DIR__"shanjiao.c",
         "eastup":AREA_QIANFO"qiyan.c",
         "east" : AREA_QIANFO"road",
	 "south" : __DIR__"gate"
               ]));
        set("objects", ([
                AREA_QIANFO"npc/horse" : 1,
		AREA_QIANFO"npc/climber" : 2,
       ]) );
        set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "���������˹�����\n");
        }
}

int do_climb(string arg)
{
        if( arg!="tree" ) return 0;

        message_vision("$N�ֽŲ��ã����ݵ���������ͤǰ�Ĵ�����\n",
                this_player());

        tell_room(__DIR__"tree1", this_player()->name() + "����������������\n");
        this_player()->move(__DIR__"tree1");

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir=="eastup") dir="east";
        tell_room(__DIR__"tree1",
                "���µ�" + me->name() + "��" + to_chinese(dir) + "�뿪�ˡ�\n");
        if (dir=="east") dir ="eastup";
        return 1;
}

