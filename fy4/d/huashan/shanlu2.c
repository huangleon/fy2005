
inherit ROOM;
void night_event();
void sunrise_event();
string tree();
string stream();
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��ɽ·�������м������壬С·�ӷ������д�������������д�������Ҷ����
��ͷ�ϻ������죬��Ҷ������Σ�ÿ������˪Ũʱ�ڣ���ɽ��Ҷ��㣬����һ����
ɫ��һ��СϪ��ɽ�����£���������ɽ����ȥ��
LONG
        );
    set("exits", ([ 
        "southeast" : __DIR__"shanlu1",
        "westup" : __DIR__"lianhua",
	]));

	set("item_desc", ([
		"maple tree" : (: tree :),
		"����" : (: tree :),
//		"stream" : (: stream :),
//		"СϪ" : (: stream :),
	]));
	
	set("objects", ([
		__DIR__"obj/nest" : 1,
	]));
    set("outdoors", "huashan");

	set("coor/x",-65);
	set("coor/y",-55);
	set("coor/z",36);
	setup();
	NATURE_D->add_day_event(19, 0, this_object(), (: night_event :)); 
}

string tree(){
	object me;
	int i;
	i = NATURE_D->get_season();
	me = this_player();
	if(i == 3){
		tell_object(me, "�����ķ�Ҷ����ƻ�\n");
		call_out("leaf_fall", random(40));
	} else if(i == 4) {
		tell_object(me, "��ͺͺ�������Ͽ��Կ�������СС�����ѡ�\n");
	} else {
		tell_object(me, "��Ҷ��綯�����������������졣\n"); 
	}
	return "";
}

void leaf_fall(){
	object leaf;
	if(!leaf = present("maple leaf", this_object())) {
		leaf = new(__DIR__"obj/mapleleaf");
		leaf->move(this_object());
		message("vision", "һƬ��Ҷ���Ʈ�¡�\n", this_object());
	}
}

void night_event() {
	object qing;
	object room = this_object();
	if(!random(2)){
		qing = new(__DIR__"npc/qing");
		qing->move(room);
		message_vision("��Ȼ��һ��紵���������з·��и�Ӱ�ӡ�һ��������Ӱ�ӣ������ֵ�����������\n", qing);
		NATURE_D->add_day_event(6, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(19, 0, this_object(), (: night_event :));
	}
}

void sunrise_event() {
    object *ob_list;
    int i;
    
    ob_list = children("/d/huashan/npc/qing");
    for(i=0; i<sizeof(ob_list); i++) {
        if(environment(ob_list[i])) {
        	message_vision("һ������������$N��ʧȥ����Ӱ��ֻ���µ�����������\n",ob_list[i]);
        }
        destruct(ob_list[i]);
    }
    NATURE_D->add_day_event(19, 0, this_object(), (: night_event :));
}
