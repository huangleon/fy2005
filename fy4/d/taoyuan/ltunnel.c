inherit ROOM;
void create()
{
        set("short", "����ˮ�ı�����°���");
        set("long", @LONG
͸��������ƵĹ��ߣ��������ˮ�о�Ȼ�м��ÿ�֦����Ƥ�Ѿ����ã�������
�˵����ţ�ˮ���䳹�ǣ����ڻ���������һ���ԴֵĿ�֦����бб�ش����������
������������е��̹��ĺۼ���
LONG
        );
	set("item_desc", ([
	"vine": "һ���ִֵĿ�֦����ˮ�ݵ÷���һ�ɹ�ζ������ģģ�����ؿ��ż���С�֣� 
		�䵱���ء�����������\n",
	"��֦": "һ���ִֵĿ�֦����ˮ�ݵ÷���һ�ɹ�ζ������ģģ�����ؿ��ż���С�֣� 
		�䵱���ء�����������\n",
	]) );
	set("objects", ([
                __DIR__"obj/vine" : 1,
        ]));
	set("no_magic",1);
	set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",-30);
        setup();
}

init() 
{
	add_action("do_move", "move");	
	add_action("do_dive","dive");
	add_action("do_search","search");
}


int do_move(string arg)
{
	object me, bat;
	int i;

        if(!arg || arg != "��֦" && arg != "vine" ) return 0;
	switch (random (2)) {
		case 0:
message_vision("$N���������ƿ�֦�����ֿ�֦��˿������\n", this_player());
		break;
		case 1:
		bat = present("bian fu", this_object());
		if(!objectp(bat)) {
message_vision("$N��ҡ����һ�¿�֦����¼¼�ɳ��˼�ֻ����\n", this_player());
			for (i=0; i<random(5)+4; i++){
 			bat = new(__DIR__"npc/bat");
			bat->move(this_object());
			bat->kill_ob(this_player());
			return 1;
			}
		}
message_vision("$Nҡ����һ�¿�֦����֦������֨֨��Ҫ���ѵ�������\n", this_player());
		break;
	}	
	return 1;
}

int do_dive()
{
	object room;
	message_vision("$N��һ�ᣬһ�������������̹ǵ�ˮ�У�\n",this_player());
	room = load_object(AREA_WUDANG"jing");
	this_player()->move(room);
	tell_object(this_player(),"\n\n����ǰͻȻһ����\n\n",this_player());
	message("vision",this_player()->name() + "ͻȻ��ˮ�����˳�����\n", environment(this_player()),this_player());
	return 1;	

}

int do_search()
{
	object me;
	object box, treasure;
	me=this_player();
	if(!me->query_temp("saw_treasure_map"))
	{
	message_vision("$N�����˫�֣��ڱ����ˮ����ѽ��������\n",me);
	return 1;
	}
	message_vision("$N�ӿ�֦�ĵط���������ǰ������һ��������ˮ�׵�����
�ڳ�һ�����У�\n",me);
	box = new(__DIR__"obj/box");
	box->move(me);
	return 1;
}
