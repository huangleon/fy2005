// octo4.c

inherit ROOM;

void midnight_event();
void sunrise_event();

void create() {
	set("short", "�˽ǽ�");
	set("long", @LONG
�������⣬Χ������Ժ�İ˽ǽ��ǲ���������������ֵĵط�����������
��ջ���̺Ŷ����������ϡ�Զ��������ʱ��������һ���������Ʈ���������ļ�
����̫�������Ž�⣬��������ʥׯ�����µľ���
LONG );
	
	set("exits", ([ 
	"west" : __DIR__"octo5",
	"east" : __DIR__"octo3",
	]));
	set("outdoors", "guanwai");
	set("objects", ([
	    __DIR__"npc/lama2" : 2,
	]) );
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}

void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(5);
	
	if(!random(20)) {
		for(i=0; i<bandit_no; i++) {
			if(objectp(badguy = new("/obj/npc/bandit"))) {
				badguy->setup_bandit("��������", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "guanwai");
				badguy->move(room);
				badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
			}
		}
		NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
	object *ob_list;
	int i;
	
	ob_list = children("/obj/npc/bandit");
	for(i=0; i<sizeof(ob_list); i++) {
		if(ob_list[i]->query("area_mark") == "guanwai") {
			if(environment(ob_list[i])) {
				message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
			}
			destruct(ob_list[i]);
		}
	}
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
