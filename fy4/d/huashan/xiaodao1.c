
inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
·��Ȼ��ɽ��ȵ��̻����У�ֻ��·��ɽ�ƽ������ϣ�һ��СϪ������С·��
һ������ȥ��Ϫˮ������������ˮ�������ų�����г�ӯ�ڶ���һ�þ޴����
����������СϪ��һ�࣬���������ϱ�������˶����Ҷïʢ�����й�����������
������
LONG
        );
    set("exits", ([ 
  		"westdown" : __DIR__"xiaodao",
	    "southeast" : __DIR__"chaoyang",
	]));
	set("resource/water", 1);
	set("liquid/container", "СϪ");
	set("liquid/name","СϪˮ");
	
	set("objects", ([
		__DIR__"npc/yellowbird" : 1,
	]));
	set("item_desc", ([
		"СϪ" : "СϪ������ˮ�峺�������Ծ��ȥ��������裩��\n",
		"stream" : "СϪ������ˮ�峺�������Ծ��ȥ��������裩��\n",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-7);
	set("coor/y",-50);
	set("coor/z",33);
	setup();
}

void init(){
	add_action("do_dash", "dash");
}

int do_dash(){
	object me, room;
	
	me = this_player();
	message_vision("$N�˺���������Ȼ�ӿ�Ų�һ��������ӯ��Խ����СϪ��\n", me);
	room = find_object(__DIR__"yinxing");
	if(!objectp(room)){
		room = load_object(__DIR__"yinxing");
	}
	me->move(room);
	message("vision", me->name() + "��СϪ������һ��Ծ�˹�����\n", environment(me), me);
	return 1;
}
