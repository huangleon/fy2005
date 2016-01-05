inherit __DIR__"no_killing_place";
string garden();
void create()
{
        set("short", "���");
        set("long", @LONG
��ª��լԺ��ʰ��ʮ�ָɾ���������ɵ�ǽΧ��һ���ķ��е�Ժ�ӣ�Ժ������
����һ��ľ�ܣ�һϯ�ƾɵ��������ڼ����ϣ����ӵ��Ա���һ��ľ�ʺ�һ��������
��ɵ�С������������Χǽ�ĵط���һС���߲˵أ���������Щ��ˡ�  
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"road1",
	]) );

	set("item_desc", ([
		"�߲˵�" : (: garden :),
		"garden" : (: garden :),
	]) );
	set("objects", ([
  		__DIR__"obj/basket": 1,
  		__DIR__"npc/caier": 1,
   		__DIR__"obj/stool":1,
   	]) );
   	set("veg_amount", 3);
    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

string garden(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1 && query("veg_amount") > 0) {
		message_vision("�߲˵��ﳤ��Щ���۵�ë����\n", me);
	} else if(i == 2 && query("veg_amount") > 0){
		message_vision("���̵�С�Ͳ˿��Ž��ɫ�Ļ��䡣\n", me);
	} else if(i == 3 && query("veg_amount") > 0){
		message_vision("�����С�и���ˮ����ġ�\n", me);
	} else if(i == 4 && query("veg_amount") > 0){
		message_vision("�ɿݵ��ټ��Ϲ��ż������ϡ�\n", me);
	} else {
		message_vision("��������һЩ���ҵ��߲ˡ�\n", me);
		return "";
	}
	tell_object(me, "��Ҳ����Բ�ժһЩ�߲ˡ�������롡����磩\n");
	add_action("do_pick", "pick");
	return "";
}

int do_pick(string arg){
	object me, veg;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(!arg || arg != "veg"){
		return notify_fail("��Ҫժʲô��\n");
	}
	if(query("veg_amount") > 0){
		message_vision("$N�Ӳ��������Щ�߲˷��뻳�С�\n", me);
		if(i == 1) {
			veg = new(__DIR__"obj/soybean");
		} else if(i == 2){
			veg = new(__DIR__"obj/youcai");
		} else if(i == 3){
			veg = new(__DIR__"obj/greenorion");
		} else if(i == 4){
			veg = new(__DIR__"obj/donggua");
		}
		add("veg_amount", -1);
		veg->move(me);
	} else {
		return notify_fail("�������Ѿ�û�в��ˡ�\n");
	}
	return 1;
}

void reset()
{
    	object *inv;
    	object item1, item2, basket, stool, item3;
    	::reset();
    	
    	basket = present("basket", this_object());
    	if (!present("suo zi",basket))
   		item2 = new(__DIR__"obj/suozi");
   	if (!present("string",basket))	
   		item1 = new(__DIR__"obj/yuxian");
        if (item1) item1->move(basket);
        if (item2) item2->move(basket);
    	
	stool = present("stool", this_object());
	if (!present("fish tank",stool))    
       		item3 = new(__DIR__"obj/fishtank");
        if (item3) item3->move(stool);
        set("veg_amount", 3);
}

