
inherit ROOM;
string flower();
void create()
{
        set("short", "����С��");
        set("long", @LONG
С·�����������֣������ڱ������գ���ʹ�ڰ�������Ҳ�Ե�ʮ��������ï��
���Ӳݼ�������������·�棬��Щ�ط�С·�����ɱ档��Զ��һ�ζ�ǽ����·�ԣ�
��ǽ�Գ�����һ�ԴԵ�Ұ�ա�
LONG
        );
    set("exits", ([ 
		"west" : __DIR__"hpath1",
		"east" : __DIR__"citang1",
	]));
 	set("objects", ([
 		__DIR__"obj/duanqiang" : 1,
 	]) );  
 	set("item_desc", ([
 		"flower" : (: flower :),
 		"Ұ��" : (: flower :),
 	]) );
 	set("flower_amount", 5);
    set("outdoors", "huashan");
	set("coor/x",-8);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

string flower(){
	int i;
	i = NATURE_D->get_season();
	if(i == 3) {
		tell_object(this_player(), "��ǽ�ߵ�Ұ�ջ���������������ժ���䣨����롡�������򣩡�\n");
		add_action("do_pick", "pick");
	} else if(i == 4) {
		tell_object(this_player(), "��ǽ�»����˲�ѩ���������Ƶ�é���ں�����ɪ���š�\n");
	} else {
		tell_object(this_player(), "��ǽ�³�����ï�ܵ�Ұ�ݻ���Ұ�ջ���\n");
	}
	return "";
}

int do_pick(string arg){
	object me, obj;
	
	if(!arg || arg != "flower"){
		return 0;
	}
	me = this_player();
	if(query("flower_amount") >= 0) {
		message_vision("$N�����ڶ�ǽ��ժ��һ��Ұ�ջ���\n", me);
		obj = new(__DIR__"obj/flower");
		if(objectp(obj)){
			obj->move(me);
		}
		add("flower_amount", -1);
		return 1;
	}
	tell_object(me,"Ұ�ջ��Ѿ���ժ���ˡ�\n");
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 5);
}
