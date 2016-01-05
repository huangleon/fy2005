inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
		��Զ�Ϻ�ɽʯ��б����������˼ҡ���
һ������ʫ��֮�У�������̵�����ɽ��֮�䣬��ӳ��һ�����飬�������������
���ż����ª�Ĳ��á�бб��ʯ������Ӣ�ͷף�һ���׷��ԲԵ��������ˣ�������
������������ɨ��ʯ���ϵ��仨��(�����������轻�����ƽ�) 
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"flowers",
		"northwest":__DIR__"fogpath",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/oldman":1,
    	]) ); 
	set("coor/x",40);
	set("coor/y",-70);
	set("coor/z",30);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("lame oldman", this_object()) ) 
        {
		if ( !me->query("marks/wolf_pass_oldman"))
		{
            return notify_fail(ob->name()+"����ɨ����ɨ����Щ��Զɨ�������仨�����������е�ס���ȥ·��\n");
		}
	}
	return 1;
}
