inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ��Ȼһ�䣬�Ӻڰ��������У�������һ���ԻͲ��õ���أ������漣��
�޴��ʯ���ϣ����Ż�������׾��ͼ�����ı���ҫ����⡣��ϸ��ȥ��ԭ���⾹Ȼ
������Ρ�������ķ���������ɳĮ���𽥳��ˡ���ʯ������������Ҳδ�뵽ɳĮ
֮�¾�������û�ΰ��Ľ�����������Ǻ�ʱ�Ի�һʱ��¥���Ź���ַ��(������
���轻�������ƽ�)
LONG
        );
        set("exits", ([ 
		"up" : __DIR__"kongquehe",
		"east" : __DIR__"weststrt3",
	]));
        set("indoors", "loulan");
        set("objects", ([
               __DIR__"npc/cai" : 1,
	]) );

	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( me->query("class") != "knight" )
        {
	        if( userp(me) && dir=="east" && ob=present("jin wuwang", this_object()) ) 
	        {
	        	if (!REWARD_D->check_m_success(me, "��ɫ����")
	        		&& !REWARD_D->riddle_check(me, "��ɫ����/cai"))
	        		return notify_fail("������һ�Բ���������΢�������������ǰ��\n");
	        }
	}
	return 1;
}


