
inherit ROOM;
void fall(object me);
void create()
{
        set("short", "������");
        set("long", @LONG
���ε�ɽ���ʲԺ�ɫ��ʯ·��Լ���ף��������ߣ�������Ԩǧ�ߣ�ÿ��ɽ��
����������Ʈ��������������վ�ƶˣ����Ƴ˷��ȥ�����˲��ɵ������ҡ������
�쳣����ʫ���������������ϣ�ز�����ѷɡ�����һ�������������ɴ��� ѭ������
�У�ʼ���ݺ�ʩ�����꼰׹�ǣ�������紵�� ��
LONG
        );
    set("exits", ([
        "westdown" : __DIR__"qianchi", 
  		"northup" : __DIR__"yuntai",
  		"southup" : __DIR__"yunv",
	    "eastdown" : __DIR__"xiaodao",
	]));
	set("objects", ([
		__DIR__"npc/gao" : 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
}

void init(){
	object me;
	string weather;
	
	me = this_player();
	if (!userp(me))	return;
		
	weather = NATURE_D->get_weather();
	
	if(weather == "���" && !random(200)) {
		message_vision("һ��紵����$N����һ�Σ�������һ�����У�$N����ɽ�¡�\n", me);
		fall(me);
	} else if(weather == "���" && !random(100)){
		message_vision("һ���紵����$N����һ�Σ�������һ�����У�$N����ɽ�¡�\n", me);
		fall(me);
	} else if((weather == "ѩ" || weather == "��ѩ") && !random(80)) {
		tell_object(me, "��ֻ���ý���һ�������Ӷ�Ȼ������һ�ߣ��㲻�ɵ÷�����һ�����С�\n");
		message("vision", "ֻ��һ�����У�$N������ɽ�롣\n", environment(me), me);
		fall(me);
	} else if(!random(600)) {
		message_vision("$Nһ����գ�������ɽ�롣\n", me);
		fall(me);
	}
}

void fall(object me){
	object room;
	if (!me)	return;
		
	room = find_object(__DIR__"yadi");
	if(!objectp(room)){
		room = load_object(__DIR__"yadi");
	}
	me->move(room);
	message("vision", "ֻ��" + me->name() + "�ӿ���׹�䣬����ͨ��һ���䵽�˵��ϡ�\n", environment(me), me);
	if ( random(2) ) me->unconcious();
}
