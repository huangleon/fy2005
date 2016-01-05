// Room: fodian.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
���пտ���Ҳ��Ҳû���ˣ��������û�У�ֻ�е�ǰ��¯��������ɢ���ŵ�
��ɫ������������������������������������������ӣ��������������Ե�
��������������˾��ÿ��¡�һ�������洵���������÷���������Ư����ɢ��
��Щ�������������������������Ʈɢ�������п����������Ǻ�Ȼȫ������˻�
�ģ���������������צ���������˶��ɡ������ƺ�������С�š�
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"south":__DIR__"bigyard",
	]) );
	set("item_desc",([
		"¯��":"һ���������Ƶ�¯�����ƺ����԰ᶯ��move����\n",
		"luding":"һ���������Ƶ�¯�����ƺ����԰ᶯ��move����\n",
		]));
	//}}
        set("indoors", "shanliu");
	set("objects", ([
	__DIR__"npc/monk2" :1,
	]) );
	set("coor/x",-2);
	set("coor/y",60);
	set("coor/z",60);
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me;
	object monk;
	if (!arg || (arg != "¯��" && arg != "luding"))
	{
		return 0;
	}
	me=this_player();
	if (!mapp(me->query("organization")) || (string)me->query("organization/org_name")!="ɽ��")
	{
		if (monk = present("old monk",this_object()))
		{
			 message_vision("$N˫�ֺ�ʮ��$n����ʩ����ɽ�����ˣ�������ذɡ�\n",monk,me);
			 return 1;
		}
	}
	if (me->query("force_factor")<=50)
	{
		return notify_fail("����������\n");
	}
	message_vision("�����ͻȻ¶�����ںڵİ�����$N��Ӱһ��������˰�����\n",me);
	me->move(__DIR__"mishi");
	//message_vision("գ�ۼ�,������ʧ����Ӱ����,һ�к���ֻ���������\n");
	tell_object(me,"��پ������ڿգ�ת˲�侹�ѵ����˼�С���С�\n");
	message_vision("$N�ӿ��е���������\n",me);
	return 1;
}
