
inherit ROOM;
string plant();
void create()
{
        set("short", "���ѳ�");
        set("long", @LONG
ɽ�����и�С������ˮɫ�����羵�������겻�ɣ�һ·����ȴҲ������Ϫ��
ע�����С�����������һЩ���̵�ֲ�΢΢ɽ�紵����������Ҷ�����ڶ���
�������ƺ�Ư����һ�ֵ�����������
LONG
        );
    set("exits", ([ 
  		"westup" : __DIR__"yuquan",
  		"eastdown" : __DIR__"zhuyu",
		"north" : __DIR__"zhandao",
	]));
   
   	set("item_desc", ([
   		"ֲ��" : (: plant :),
   		"plant" : (: plant :),
   	]) );
    set("cpleaf_amount", 3);
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-20);
	setup();
}

string plant(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if (i == 4) {
		tell_object(me, "Сˮ���ϸ���һ�㱡����ˮ�ߵ�ֲ�ﶼ�ѿݻơ�\n");		
	} else {
		tell_object(me, "ǳˮ������һ�ԴԵ���ɫֲ�������Ҷ�Ӵ���΢΢��������\n");
		add_action("do_pick", "pick");
	}
	return "";
}
int do_pick(string arg){
	object obj, me;
	int i;
	me = this_player();
	if(!arg || (arg != "leaf" && arg != "����" && arg != "plant" )) {
		return 0;
	}
	if(query("cpleaf_amount") > 0) {
		obj = new(__DIR__"obj/cpleaf");
		if(objectp(obj)){
			obj->move(me);
			message_vision("$Nժ�˼�ƬҶ�ӷ��뻳�С�\n", me);
			add("cpleaf_amount", -1);
		}
	} else {
		tell_object(me, "û���ˡ�\n");
	}
	return 1;
}
void reset(){
	::reset();
	set("cpleaf_amount", 3);
}
