inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ��Ȼһ�䣬�Ӻڰ��������У�������һ���ԻͲ��õ���أ������漣��
�޴��ʯ���ϣ����Ż�������׾��ͼ�����ı���ҫ����⡣��ϸ��ȥ��ԭ���⾹Ȼ
������Ρ�������ķ���������ɳĮ���𽥳��ˡ���ʯ������������Ҳδ�뵽ɳĮ
֮�¾�������û�ΰ��Ľ�����������Ǻ�ʱ�Ի�һʱ��¥���Ź���ַ��
LONG
        );

        set("exits", ([ 
		"up" : __DIR__"kongquehe",
		"south" : __DIR__"northstrt2",
	]));
        set("objects", ([
		__DIR__"npc/qi" : 1,
	]) );
        set("indoors", "loulan");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( me->query("class") != "knight" )
        {
	        if( userp(me) && dir=="south" && ob=present("dugu shang", this_object()) ) 
	        {
	        	if( !me->query_temp("marks/knight_win_dugu")
	        		&& !REWARD_D->check_m_success(me, "��ɫ����"))                
	               return notify_fail("���������������Ӯ�ң���ȥ�������ˣ���������\n");
	        }
	}
	return 1;
}
