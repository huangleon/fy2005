// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
    set("short", "Сɽ�¶�");
    set("long", @LONG
ɽ���䲻�ߣ����Ǹ���û�иߴ����ľ���������������ؿ���������Ƴǵķ�
����ռ�ؼ�����ķ��Ƴ�һ���������߼ʣ��˽��εĳ�ǽΧ����̽����߸ߵش���
�ڳ����ģ����ϴ���ǽ��������������ǧ��¥��������һ����ΰ�ĸ����������·�
��������⣬�յ��㼸���������ۡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"westdown" : __DIR__"fysroad1",
      ]));
    set("objects", ([
	AREA_FY"npc/shiren": 1,
	AREA_WANMEI"obj/tree" : 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",60);
    set("coor/y",-540);
    set("coor/z",20);
    setup();
}
