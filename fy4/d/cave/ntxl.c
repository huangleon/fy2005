// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������·");
        set("long", @LONG
�����ܵͣ�����ʹ��վ��վ��ֱ��������һֱ�ε����յ������ڵ�ˮ��ˮ�ʻ�
�Ƿ�ճ�����µİ��ӷ���¡¡���������ƺ�������ת�䡣·��ͷ�Ǽ�ʯ�ݣ���Լ��
���谵�ĵƹ���ŷ���͸����
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"tzdx",
  		"south" : __DIR__"ntxm",
	]));

	set("item_desc", ([
	]));
	set("objects", ([
                        ]) );
    set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}
