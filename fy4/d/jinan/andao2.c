inherit ROOM;
void create()
{
	set("short", "Ѫɫͨ��");
	set("long", @LONG
������ͨ�����ε�ͨ����һ·��Ѫ����أ������Ż������ص�����������
����ѷɡ�һ�������ź���һ��������������ľ��ͨ�����Σ���һ�����޵�
���Ŷ��ױ��������صء�ͨ������һ����η���ͨ���⼣�߲�����������Կ�
��һ��������ĥ�ò������ε������������Ĳҽв�ʱ���������
LONG
        );
        
	set("exits", ([ /* sizeof() == 4 */
		//"west" : __DIR__"andao1",
		//"east" : __DIR__"prison",
		//"southdown" : __DIR__"prison2",
	]));

	set("objects", ([
		__DIR__"npc/guard2" : 1,
		__DIR__"npc/guard1" : 1,
	]) );

	set("item_desc", ([
		"wooddoor": "һ�����Ŵ�������ľ�ţ�������Կ�״򿪣��������룩��\n",
		"ľ��": "һ�����Ŵ�������ľ�ţ�������Կ�״򿪣��������룩��\n",
        "����": "һ�����Ŵ����������ţ�������Կ�״򿪣��������룩��\n",
        "irondoor": "һ�����Ŵ����������ţ�������Կ�״򿪣��������룩��\n",
	]) );
        
	set("no_fly",1);
	set("jinan_prison",1);
	set("coor/x",60);
	set("coor/y",10);
	set("coor/z",-10);
	
	setup();
}

void do_kill(object ob)
{
	int i;
	object *inv;
	
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("prison_guard"))
			inv[i]->do_alert(ob);
	}
	return;
}

void do_open1(){
	object room;
	this_object()->set("exits/east",__DIR__"prison");
	if (!objectp(room=find_object(__DIR__"prison"))) 
		room=load_object(__DIR__"prison");

	room->set("exits/west",__DIR__"andao2");
	return;
}

void do_open2(){
	object room;
	this_object()->set("exits/southdown",__DIR__"prison2");
	if (!objectp(room=find_object(__DIR__"prison2"))) 
		room=load_object(__DIR__"prison2");

	room->set("exits/northup",__DIR__"andao2");
	return;
}

void do_open(){
	if (random(2) && !query("exits/east"))
		do_open1();
	else
		do_open2();
	return;
}

void init()
{       
	if(!this_player()->query_temp("show_order") && userp(this_player())) {
		do_kill(this_player());
	}
	add_action("do_unlock", "unlock");
}

int do_unlock(string arg){
	object ob,room;
	if (!objectp(ob=present("key",this_player())))
		return notify_fail("������û��Կ�ס�\n");
	if (!ob->query("prison_key"))
		return notify_fail("������û�к��õ�Կ�ס�\n");
	if (arg!="ľ��" && arg!="wooddoor" && arg!="����" && arg!="irondoor")
		return notify_fail("��Ҫ����һ���ţ�\n");
	if ((arg=="ľ��" || arg=="wooddoor") && this_object()->query("exits/southdown"))
		return notify_fail("ľ���Ѿ������ˡ�\n");
	if ((arg=="����" || arg=="irondoor") && this_object()->query("exits/east"))
		return notify_fail("�����Ѿ������ˡ�\n");	
	message_vision("$N��Կ�ײ������ף�����һš�����Ÿ�֨һ�������ˡ�\n��Կ��ȴ���������󣬰ȴ�һ�¶��ˡ�\n",this_player());
	ob->set("name","���˵�"+ob->query("name"));
	ob->set("prison_key",0);
	if (arg=="ľ��" || arg=="wooddoor"){
		//"southdown" : __DIR__"prison2",
		do_open2();
	}
	if (arg=="����" || arg=="irondoor"){
		//"east" : __DIR__"prison",
		do_open1();
	}
	return 1;
	
}


int reset(){
	
	if (query("exits/southdown"))
		delete("exits/southdown");
		
	if (query("exits/east"))
		delete("exits/east");
	::reset();
}