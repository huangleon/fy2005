inherit ROOM;

void create()
{
	set("short", "ɽ��");

	set("long", @LONG
������ȥ����ɽׯ��ɽ���ϣ��¿��������������������̣�����������������
�Ĺ��ͼ�����һ̧ͷ���ֿɿ��������������״��������ӥ״�ķ��ݸ߸߷�������
������С�ɽ�����죬�������ƣ������о������Եá�������̽ͷ��ȥ���ѿ���Լ
��������ɽׯ��ͭ����š�
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "northup":__DIR__"shandao1",
		"southwest":__DIR__"shandao3",
	]) );
	
	set("objects", ([
        	__DIR__"npc/silverant" : 1,
        ]) );

	set("coor/x",10);
	set("coor/y",170);
	set("coor/z",60);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;
        if( userp(me) && dir=="northup" && ob=present("silver ant", this_object()) ) 
        {
        	if( !me->query_temp("marks/silverant")
        		&& !REWARD_D->riddle_check(me,"�ɹ�����/������")
            	&& !REWARD_D->check_m_success(me,"�ɹ�����"))
                	return notify_fail("������˫��һ�����ߵ�һ����������ɽׯ�ﻹ�����Ǹ��������ߣ�
�����˵Ȼ���ĪҪ���ⷬ��ˮ�ĺá���\n");
        }
	return 1;
}
