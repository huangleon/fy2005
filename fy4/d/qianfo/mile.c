// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���յ�");
  set("long",@LONG
���շ�Ϊ���ɮ�������ˣ����������������޺㣬���ȸ����������������ϣ�
����ϲ��֮�ࡣ���������׶������������ҡ�
LONG
  );
  set("exits",([
            "south":__DIR__"tianwang.c",
//            "north":__DIR__"weituo.c",
            "west" :__DIR__"fatang.c",
            "east" :__DIR__"chantang.c"
               ]));
        set("item_desc", ([
                "���շ�": "
                        ���շ�����һֱ��Ц��Ц��Ц������\n",
                "milefe": "
                        ���շ�����һֱ��Ц��Ц��Ц������\n"

        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}
void init()
{
add_action("do_smile","smile");

}
int closepath()
{
        if( !query("exits/north") ) return 1;
        message("vision",
"����ǽ�ϵİ�����������Ϣ�ĺ����ˡ�\n",
                this_object());
             delete("exits/north");
	return 1;
}
int do_smile()
{
	add("num",1);
	if(!((int) query("num") % 5))
		if( !query("exits/north"))
		{
			set("exits/north",__DIR__"weituo");
			message("vision",
"���շ��ƺ�Ҳ����һ��Ц������������ྲ꣢һ���������ǽ���ѳ���һ�����š�\n",
			this_object());
			call_out("closepath",4);
			return 1;
		}
		return 0;
		
}
void reset()
{
::reset();
delete("num");
}
