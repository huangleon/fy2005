inherit ROOM;

void create()
{
        set("short", "���·");
        set("long", @LONG
��������ɽ��������ǲ�·�ڣ����ϵ�·����������ֱͨ����ʥ��[33m�䵱ɽ[32m����
����Ũ��֮��������һ������ɫ����壬ֱ�������������м�ͷ��ӥ�ڵ͵͵�����
���裬�·���Ѱ������������[33m����ɽ[32m���������ƣ�ɽ�����м����˼ҡ�����
һ�ν���˼������ʱ����ʱ���� 
LONG
        );
        set("exits", ([ 
  	"east" : 	__DIR__"palace_path2",
  	"west" : 	AREA_FYCYCLE"fyeast",
  	"northeast" :   AREA_CHUENYU"dustyroad0",
  	"south" :       AREA_WUDANG"bwuroad1",
]));
        set("outdoors", "palace");

	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_go","go");
}


int do_go(string dir){
	
	object me;
	object *inv, ob;
	mixed *local;
	int i,flag=0;
	

	me = this_player();
	local = NATURE_D->getTime(time());

	if (userp(me) && me->query("class") == "moon"	&& dir == "east")
	{
		ob = find_object("/d/xiangsi/qishi");
		if (!ob)
			ob=load_object("/d/xiangsi/qishi");
		message_vision("ɽ��ͻȻƮ��һ��Ũ����ʱ�������ߵľ�ɫ�౻��ס��\n",me);
		me->move(ob);
		tell_object(me,"������۾���������Ϥ�ļ���ת�룬̤����˼���С�\n");
		message("vision","Ũ��ת�ۼ���ɢ���٣����������ƺ�ͻȻ����һ����Ӱ������\n",this_object()); 
		return 1;
	}

	if( userp(me))
	{
		if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 0)
			me->set_temp("annie/xiangsi_enterance",1);
		else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 6)
		{
			if (local[1] == 0 || local[1] == 6 || me->query_temp("marks/xiangsi/entrance")
				|| REWARD_D->check_m_success(me,"��ɽ֮��"))
			{
				ob = find_object("/d/xiangsi/qishi");
				if (!ob)
					ob=load_object("/d/xiangsi/qishi");
				message_vision("ɽ��ͻȻƮ��һ��Ũ����ʱ�������ߵľ�ɫ�౻��ס��\n",me);
				me->move(ob);
				tell_object(me,"���ڴ�������ɽ���е�Ƭ�̣���Ȼ���������ľ�ɫ��������д���ͬ��\n");
				if (!REWARD_D->check_m_success(me,"��ɽ֮��")) {
					REWARD_D->riddle_done( me, "��ɽ֮��",10,1);		
					tell_object(me,"\b�����ס������ĵ��Σ��Ժ������ٵȴ�����˫ʱ�ˡ���\n");
				}
				me->set_temp("marks/xiangsi/entrance",1);
				me->delete_temp("annie/xiangsi_enterance");
				message("vision","Ũ��ת�ۼ���ɢ���٣����������ƺ�ͻȻ����һ����Ӱ������\n",this_object()); 
				return 1;
			}
			else
				me->delete_temp("annie/xiangsi_enterance");
		}
		else
			me->delete_temp("annie/xiangsi_enterance");
	}
	
	return 0;
}
