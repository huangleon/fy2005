
inherit ROOM;

void create()
{
    set("short", "�η�");
	set("long", @LONG
�����ǹ�Ѻ���˵ĵط�������ʮ�߼������η���û�д�齱��죬ֻ�м��ѿݻ�
ɢ����������ζ�ĵ��ݣ���ʱ���д��������Ľ����ܹ�����֪������Ʈ���ĸ���
֮������������η������źڰ����η����ʱ��Զ���������˵ĺ�������
 [33m�����������������[32m
LONG
	);
    	set("indoors", "jinan");
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	set("valid_startroom",1);
	set("no_magic", 1);
	setup();
}
void init()
{
	this_player()->set("startroom", base_name(this_object()));
	add_action("do_listen", "listen");
}

int do_listen(string arg)
{ 
	object player;
	player = this_player();
	if (arg == "sound" || arg== "������")
	{
		tell_object(player,"��С�ĵ�������Զ���η���ĺ�����������ΧͻȻ������һ��ļž��С�\n");
		tell_object(player,	"һ��̿�ӿ����ͷ���㲻�����������(yell help) \n") ;
		add_action("do_yell","yell");
	}else
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}
	return 1;
}

int do_yell(string arg)
{
	object player,yuzuzhang;
	player = this_player();
	if (arg != "help")
	{
		return notify_fail("��Ҫ��������ʲô��\n");
	}else
	{
		message_vision("$N��˻���ߵش󺰣��������˰������ҳ�ȥ��������\n",player);
		if (!random(3))
		{
			
			if (yuzuzhang = present("yuzu zhang",this_object()))
			{
				return notify_fail("���䳤������æ���ģ�û�����㣡�Ȼ�������԰ɡ�\n");
			}else
			{
				yuzuzhang = new(__DIR__"npc/yuzuzhang");
				yuzuzhang->move(this_object());
			}
			
			message_vision("ֻ��$N�������˹��� \n",yuzuzhang);
			yuzuzhang->release_player(player);
		}
		else
		{
			tell_object(player,"��ֻ��������ҵĽ����ڿյ������η��лص������Ӽ�������Ŀ־塣\n");
		}
	}
	return 1;
}
