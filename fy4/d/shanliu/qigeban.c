// Room: qigeban.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "�߸���");

	set("long", @LONG
���ﱾ��һ��ܴ�Ŀյأ�������ȴ�ݲݴ��˸�ţ�����ӡ��ϰ���Ǹ���һ��
���������"�߸���"���������о��б����Ѻ���������������������˸�ţ��̯�ӣ�
����ţ����Ҳ�ã������Ҳ�ã���ֻ���߸����Ǯһ�롣��ʮ�����Ӷ����������ˣ�
���ٻ��������뻪�󡣸�ʽ������ͬ���ˡ��յص��Աߣ���ͣ�źܶ೵��һ��Ƭ
�յ��ϣ�ֻ����ǰ����ż��������������ѱ�����Ѭ�ڣ������Ͳ�̫���� 
LONG);
	//{{ --- by MapMaker
	set("exits",([
	"southdown":__DIR__"nilu3",
	//"northeast":__DIR__"nilu4",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/sevenhalf" :1,
	__DIR__"npc/haoke"  :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",50);
	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object me,room;
	me=this_player();
	if (arg != "curtain") return 0;
	if (me->query_temp("ɽ��/�߸���") 
		|| (mapp(me->query("organization")) 
		&& (string)me->query("organization/org_name")=="ɽ��"))
	{
		message_vision("$N�ƿ�ţ�����Ӻ�����Ѭ�÷ֲ�����ɫ�����ӡ�һ�������˽�ȥ\n",me);
		room = find_object(__DIR__"nilu4");
		if (!room)
		{
			room = load_object(__DIR__"nilu4");
		}
		me->move(room);
		return 1;
	}
	return 0;
}
