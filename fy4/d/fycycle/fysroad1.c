// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
    set("short", "Сɽ������");
    set("long", @LONG
�����߼�����Ƿ��Ƴǣ�������ʱ����ԼԼ�ػ����Կ������ｨ���ĺ�ɫ��
������������һ����ͺͺ��Сɽ�£������ѱ�·��������̤����һ������·��·
�����߻�����һЩ���˸ߵĽ���é�ݡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"eastup" : __DIR__"fysroad2",
	"north" :  __DIR__"fysouth",
	"south" : __DIR__"fyroad0",
      ]));
    set("objects", ([
	__DIR__"obj/grass" : 1,
      ]) );
    set("outdoors", "fengyun");

    set("coor/x",0);
    set("coor/y",-380);
    set("coor/z",0);
    setup();
}

void reset()	{
    object con, item, *inv;
    ::reset();
    if( con = present("grass",this_object()))
	if( inv = all_inventory(con))
	    if( !sizeof(inv))
	    {
		item = new( AREA_FY"obj/9whip");
		item->move(con);
	    }	
}




