inherit ROOM;

void create()
{
	set("short", "ɽ��");

	set("long", @LONG
���˴˴���ɽ�ƽ���ƽ̹Щ���ѿɴ��¿�����Զ�ĸ���ɽׯ������һ������
��ɽ���ϵķ��ӣ����Ӻܴ󣬽����ú��ûʡ���ʾ����һ������Ǯ�������Ӿ��뼪
����Ҳ̫Զ��Щ��Ҳ̫ƫƧ��Щ��������ֱ��˵�ǻ������̣������ⷿ������ĵ�
�������Ƿس���
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "southdown":__DIR__"shandao2",
        "northup":__DIR__"damen",
	]) );
	set("objects", ([
       		__DIR__"npc/goldant" : 1,
        ]) );



	set("coor/x",10);
	set("coor/y",180);
	set("coor/z",70);
	setup();
	
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;

        if( userp(me) && dir=="northup" && ob=present("gold ant", this_object()) ) 
        {
        	if( !me->query_temp("marks/goldant")
        		&& !REWARD_D->riddle_check(me,"�ɹ�����/������")
            	&& !REWARD_D->check_m_success(me,"�ɹ�����"))        		
                	return notify_fail("������˫��һ�����ߵ�һ����������ɽׯ�ﻹ�����Ǹ��������ߣ�
�����˵Ȼ���ĪҪ���ⷬ��ˮ�ĺá���\n");
        }
		return ::valid_leave(me,dir);
}
