inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "����÷֦��");
        set("long", @LONG
һ���øɿݵ�÷֦�����ׯ�������š���������һ����ͭ���塣����翪�ϣ�
���巢���϶������Ķ���֮������������һ�У�
                �޽�Ϊ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"village",
  "east" : __DIR__"frontyard",
]));
        set("outdoors", "wanmei");
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}


int valid_leave(object me, string dir)
{
	if(dir == "east"){
    
    if( me->query_temp("played_qin"))
	{
	        if(!REWARD_D->check_m_success(me,"������÷"))
	        {
	        	REWARD_D->riddle_done(me,"������÷",10,1);
	      	}
		return 1;		
	}
	else
			return notify_fail("һ��ǿ���������ס���㡣\n");
	}
	return 1;
}

