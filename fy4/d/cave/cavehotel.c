// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ʳ��");
        set("long", @LONG
������ʯ���ɵķ��ݱ���Ѭ���ǵ���ڣ��ſ���ش��Ÿ����ӣ���������
���˲��д�š���ʳ�á������֣����󷹲�������洫��������֮�����ͨ������
�ŷ�����������ʳ�͡��ں�����ǽ������Ѫд�ż���������(sign)��
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"zx",
  		"north" : __DIR__"storage",
	]));
	set("item_desc", ([
                "sign": @TEXT

                ��߻ʵ�Զ������ǿ���࣡
                ����һ̧ͷ���ĺ������ڣ�

       ���˶��ϣ�����������ؽ磬����ն�񣬼���ɱ�٣�

TEXT,
            ]) );
	
	
    set("objects", ([
        __DIR__"npc/cavewaiter": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
/*
int valid_leave(object obj, string dir){
	if(dir == "south"){
		return notify_fail("��δ����������\n");
	}
	return 1;
}
*/
