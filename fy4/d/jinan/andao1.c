inherit ROOM;
void create()
{
	set("short", "Ѫɫͨ��");
	set("long", @LONG
������ͨ�����ε�ͨ����һ·��Ѫ����أ������Ż������ص�����������
����ѷɡ�һ�����ź󣬱���һ��������������ľ�ţ��������һ�����ţ���
��һ�����޵İ��š�ͨ������һ����η���ͨ���⼣�߲�����������Կ���һ
��������ĥ�ò������ε������������Ĳҽв�ʱ���������
LONG
        );
        
	set("exits", ([
		"westup" : __DIR__"dalao1",
	]));
	
	set("objects", ([
		__DIR__"npc/guard" : 2,
	]) );

	set("item_desc", ([
		"door": "һ����������Ĵ��ţ�����һ�Ѿ޴��ͭ��������ȥ����������\n�����⣬Ψ��Ӳײ���������ˡ���\n",
		"����": "һ����������Ĵ��ţ�����һ�Ѿ޴��ͭ��������ȥ����������\n�����⣬Ψ��Ӳײ���������ˡ���\n",
	]) );
	
	set("jinan_prison",1);
	set("no_fly",1);
	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",-10);
        
	setup();
}

void do_open(){
	object room;
	this_object()->set("exits/east",__DIR__"andao2");
	if (!objectp(room=find_object(__DIR__"andao2"))) 
		room=load_object(__DIR__"andao2");

	room->set("exits/west",__DIR__"andao1");
	return;
}


void init()
{
	add_action("do_bump", "bump");
}

int do_bump(string arg){
	object obj;
	
	if (this_object()->query("exits/east")) 
		return notify_fail("�����Ѿ������ˡ�\n");
	if (objectp(obj=present("prison guard",this_object()))) {
		if (obj->query("prison_guard"))
			return notify_fail("�������������ԣ�û�취ײ�š�\n");
	}
	if (this_player()->query("force_factor")>80 && this_player()->query("force")>80 ){
		message_vision("$N�����۵�����һ����Ӳ����������ײ�˹�ȥ�� \n",this_player());
		message_vision("�����ں�¡�������б�$Nײ���ˡ� \n",this_player());
		this_player()->add("eff_kee",-(int)(this_player()->query("max_kee")/5));
		this_player()->add("kee",-(int)(this_player()->query("max_kee")/5));
		this_player()->set_temp("last_damage_from","�ڼ��ϴ���ײ�Ŷ�����\n");
		this_player()->set("force",0);
		do_open();
	}
	else{
		message_vision("$N���һ������������������ײ����ȥ��������ȴ��˿������ \n",this_player());
		message_vision("$N���ͷһ��һ����Ѫ���˳����� \n",this_player());
		this_player()->add("eff_kee",-(int)(this_player()->query("max_kee")*4/5));
		this_player()->add("kee",-(int)(this_player()->query("max_kee")*4/5));
		this_player()->set_temp("last_damage_from","�ڼ��ϴ���ײ�Ŷ�����\n");
		this_player()->set("force",0);
	}
 	return 1;
}

int reset(){
	if (query("exits/east"))
		delete("exits/east");
	::reset();
}