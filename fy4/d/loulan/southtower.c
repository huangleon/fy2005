inherit ROOM;

void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
�����ǰ��Ȼһ�䣬�Ӻڰ��������У�������һ���ԻͲ��õ���أ������漣��
�޴��ʯ���ϣ����Ż�������׾��ͼ�����ı���ҫ����⡣��ϸ��ȥ��ԭ���⾹Ȼ
������Ρ�������ķ���������ɳĮ���𽥳��ˡ���ʯ������������Ҳδ�뵽ɳĮ
֮�¾�������û�ΰ��Ľ�����������Ǻ�ʱ�Ի�һʱ��¥���Ź���ַ��
LONG
        );
        set("exits", ([ 
		"up" : __DIR__"kongquehe",
		"north" : __DIR__"southstrt2",
		]));
        set("objects", ([
               __DIR__"npc/se" : 1,
		]) );
        set("indoors", "loulan");
		set("coor/x",0);
		set("coor/y",-50);
		set("coor/z",0);
		setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( me->query("class") != "knight" )
        {
	        if( userp(me) && dir=="north" && ob=present("jiangzuo situ", this_object()) ) 
	        {
	        	if (!REWARD_D->check_m_success(me, "��ɫ����")
	        		&& !REWARD_D->riddle_check(me, "��ɫ����/se"))                 
	               return notify_fail("����˾ͽ�ȵ�����վס����ү�ڰ�ϲ���أ���һ��ȥ����\n");
	        }
	}
	return 1;
}

