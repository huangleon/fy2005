inherit ROOM;
string tree();
void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ������֣����з�����������Ӣ�ͷף�һ�㵭���ı��������
����Ĳ��㣬�����ڿ���֮�С�ż����һ�����������������Գ��ľ����������С
·�ѱ��仨���������ѱ治���ۼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin1",
  "west" : AREA_WUDANG"xiaozhen",
]));

	set("item_desc", ([
	    "����": (: tree :),
	    "peach tree": (: tree :),
	    "tree" : (: tree :),
	]) );

 	set("objects", ([	
	__DIR__"obj/grass": 1,
	]) );
	set("flower_amount", 2);
	set("peach_amount", 3);

   	set("outdoors","taoyuan");
	set("coor/x",-80);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

string tree(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1) {
		if(query("flower_amount") > 0) {
			tell_object(me, "�ͷ׵��һ��Ʋ�ϼ�����������ۺ�ɫ�������֦������ǰ̧�ֿɼ��ĵط���\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "�ͷ׵��һ��Ʋ�ϼ��\n");
		}
	} else if (i == 2) {
		if(query("peach_amount") > 0) {
			tell_object(me, "���Ͻ����������Ĵ����ӡ�\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "����֦�ĸߴ������ż�����ɬ�����ӡ�\n");
		}
	} else if (i == 3) {
		tell_object(me, "ï�ܵ���Ҷ�Ѿ���ʼ�����ˡ�\n");
	} else {
		tell_object(me, "��ͺͺ����֦��ʲô��û�С�\n");
	}
	return "";
}

int do_pick(string arg)
{
   	object me, tao;
	int i;
	
	i = NATURE_D->get_season();
   	me = this_player(); 
   	if(!arg ) {
   		return 0;	
   	}
   	if (i == 2 && (arg == "peach" || arg == "����")){
    	if(query("peach_amount") > 0) {
    		tao = new(__DIR__"obj/taozi");
      		tao->move(me);
      		add("peach_amount", -1);
      		message_vision("\n$N����ժ��һ������������������\n", me);
   		} else { 
      		tell_object(me,"���Ӷ���ժ���������� \n");
    	}
    } else if (i == 1 && (arg == "flower" || arg == "taozhi" || arg == "��֦")){
    	if(query("flower_amount") > 0) {
    		message_vision("\n$N��������һ֦�һ���\n", me);
    		add("flower_amount", -1);
    		tao = new(__DIR__"obj/taozhi");
    		tao->move(me);
    	} else {
    		tell_object(me, "û�л��ˡ�\n");
    	}
    } else {
    	return 0;
    }
    return 1;
}

void reset()
{
   object *inv;
   object item1, item2, grass;
   ::reset();

	set("flower_amount", 2);
	set("peach_amount", 3);
   grass = present("grass", this_object());
   inv = all_inventory(grass);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/petal");
      item2 = new(__DIR__"obj/mushroom");
      item1->move(grass);
      item2->move(grass);
   }
}

