inherit ROOM;

void create()
{
	set("short", "ɽ��");

	set("long", @LONG
������ȥ����ɽׯ��ɽ���ϣ��¿��������������������̣�����������������
�Ĺ��ͼ�����һ̧ͷ���ֿɿ��������������״��������ӥ״�ķ��ݸ߸߷�������
������С�ɽ�����죬�������ƣ������о������Եá�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "eastdown":__DIR__"shandao5",
        "northup":__DIR__"shandao3",
	]) );
	
	set("objects", ([
        	__DIR__"npc/redant" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",150);
	set("coor/z",50);
	setup();
	
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;
        if( userp(me) && dir=="northup" && ob=present("red ant", this_object()) ) 
        {
            if( !me->query_temp("marks/redant")
           // 	&&!me->query_temp("marks/������")
            	&&! REWARD_D->riddle_check(me,"�ɹ�����/������")
            	&&! REWARD_D->check_m_success(me,"�ɹ�����"))
                return notify_fail("������˫��һ�����ߵ�һ����������ɽׯ�ﻹ�����Ǹ��������ߣ�
�����˵Ȼ���ĪҪ���ⷬ��ˮ�ĺá���\n");
        }
		return 1;
}
