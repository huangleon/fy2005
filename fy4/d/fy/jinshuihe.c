// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "��ˮ�����");
    set("long", @LONG
һ�����������Ľ�ˮ�ӣ��������������ˮ��·�����ٷ磬������������
�������������ʯʯ��ͨ��԰���������ν����·�š����˵�������֮·��������
�ơ������š����������������ߵģ��������ŷ�Ϊ��Ʒ���š�����һ���Ա���ߡ�
LONG
    );
    set("exits", ([ 
	"south" : __DIR__"hall",
	"enter" : __DIR__"taihedian",
      ]));
    set("objects", ([
	__DIR__"npc/jindian_guard" : 2,
      ]));

    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",260);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

int valid_leave(object me, string dir){
    object silk;

    if (dir=="enter") {

	return notify_fail("�Ͻ�����ޣ��ݲ����š�\n");

	if( sizeof(me->query_all_condition()) != 0 )
	    return notify_fail("�������״���Ͻ�����ķس���\n");

	if(me->query("eff_sen")<me->query("max_sen")*9/10
	  ||me->query("eff_kee")<me->query("max_kee")*9/10
	  ||me->query("eff_gin")<me->query("max_gin")*9/10)
	    return notify_fail("�������ಡ���Ͻ�����ķس���\n");

	/*      if(dir == "enter" && present("palace guard")) {
		silk = present("silk", obj);
		if(obj->is_naked()){
				return notify_fail("�����ʿ�ȵ�����վס����������ɺ���ͳ����\n");
			} 
		if(obj->query("bellicosity") > 100 || obj->query_temp("weapon") || obj->query("vendetta/authority") || !objectp(silk)) {
				return notify_fail("�����ʿ��ɫһ����ŭ�ȵ�����ֹ������\n");
			}
		if(objectp(silk) && silk->query("equipped") != "worn")
				return notify_fail("�����ʿ��ɫ���͵ص���������װ�ã���\n");
			if(objectp(silk) && silk->query("equipped") == "worn"){
				message_vision("�����ʿһ��ȭ�����������λ"+RANK_D->query_respect(obj) +"���ܹܷԸ����������߲�˿�д����������ߣ�\n\n",
						obj); 
				return 1;
			}
		}	*/
    }
    return 1;
}
