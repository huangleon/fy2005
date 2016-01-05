// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIY"�Ͻ��"NOR);
    set("long", @LONG
���ŵ���̤�׶��ϣ����Ǿ������ӵĽ��Ǵ���ˣ��ֳ�̫�͵���ڹ�����ʮ��
���ľ�����������������ΡȻ��������ǰ�������ľ���������������������
ǧ�ˣ������ǵ�ߴ����ɣ��������������̾ͣ�����ƽ�һ��ԻͲ��á�
LONG
    );
    set("exits", ([ 
	"out" : __DIR__"jinshuihe",	
      ]));
    set("item_desc", ([
	"���ǵ" : "���ǵ�ߴ����ɣ��������������̾ͣ�ʮ�ֹ⻬����֪�Ƿ����Ծ(jump)��ȥ��\n",  
      ]));

    set("indoors", "fengyun");
    set("coor/x",0);
    set("coor/y",270);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

void init(){
    add_action("do_jump", "jump");
}

int do_jump(string arg){
    object me, room;
    int i, j;
    string *rooms = ({"zijin_w", "zijin_e", "zijin_n", "zijin_s"});
    me = this_player();
    if(!arg || (arg != "up" && arg != "���ǵ")){
	return notify_fail("��Ҫ����������\n");
    }
    j=random(4);
    message_vision("$N����һԾ��������ӯ�ĵ����˽��ǵ��\n", me);
    room = find_object(__DIR__+rooms[j]);
    if(!objectp(room)){
	room = load_object(__DIR__+rooms[j]);
	me->move(room);
    }
    return 1;
}
