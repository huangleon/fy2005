// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ƫԺ");
        set("long", @LONG
Ժ��������[37m÷��[32m���硣ÿ�ö�����׳�ɳ�����Ȼ���˾����չˡ�÷��֮�仹��
�˹����ѵ�С�ӹ�����������ˮ�������ʣ������ÿһ�����硣�����ڶ����ɣ�
��Ȼ�Ǳ���Ӫ���ķ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "÷��": "���ƺ����Կ�������𣩼���������\n",
                "tree": "���ƺ����Կ�������𣩼���������\n",

        ]) );
		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}
void init()
{
		add_action("do_chop","chop");
}


do_chop()	{
	object vege;
	if((int) query("pulled") <= 20)
	{
		vege = new(__DIR__"obj/tree");
		if (!vege->move(this_player()))
			{
				write("̫��̫���ˣ�û�����ˣ�����\n");
				destruct(vege);
				return 1;
			}
		write("�㿳��һ��÷��������ڻ��\n");
		add("pulled",1);
		return 1;
	}
	else
        write("�����˿����ˣ���\n");
        return 1;
}



void reset()
{
	:: reset();
	delete("pulled");
}
