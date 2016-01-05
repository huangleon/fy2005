inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���λ����ɽ֧�������ڳ�ɽ��´�е�ɽ���ɴ������й��������������ߴ�
ͦ�ε�[37m����[32m��[37m����[32m��[37m����[32m��˵�������ֵ�[37m��ľ[32m���ʻ���������ʢ�ĵ������£�����
���������ޱȣ����˸е������泩��
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"chairong",
  		"south" : __DIR__"bingchuan",
  		"east" :  __DIR__"goudi",
	]));

        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-60);
		set("coor/z",0);
		setup();
}

void init()
{
   	add_action("do_look", "look");
}

int do_look(string arg)
{
   	object me;

   	me = this_player();

   	if (arg == "����" || arg == "����" || arg == "��ľ") {
   		tell_object(me, "�������Ȼ����ǰ�������" + arg + "��Ȼ���������дС�\n");
   		return 1;
   	}
   		
   	if (arg == "����" || arg == "������" || arg == "yangshu") {
   	  	tell_object(me, "�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����
�����ڿޣ���Ŀ���ƺ������ڵ���һ�������ϡ�\n");
		me->set_temp("marks/xj_noticed_yangshu",1);
		return 1;
	}

	if ( (arg == "����" || arg == "dirt") && me->query_temp("marks/xj_noticed_yangshu")){
		tell_object(me,"һ�Ѻ�ɫ��������������������������ڹ�ʲô��\n");
		me->set_temp("marks/xj_noticed_dirt",1);
		return 1;
	}
	
	return 0;
}
	
	
void dig_notify()
{
	object me, box;
	int llvl;
		
	me = this_player();
	llvl = (int)me->query("kar");
	
	box = present("iron box", this_object());
	
	if (!me->query_temp("marks/xj_noticed_dirt")){
		tell_object(me,"������ڵ��������������ڱ�������ɽ�����۵ð�����ʲôҲû���ҵ���\n");
		return;
	}		
		
	if(llvl > 12 ) {
		tell_object(me,"��˳����������λ��������ȥ��\n");
		if (query("already")) {
			tell_object(me,"���ϳ�����һ�����ӣ����˸����֦Ҷ����ʲô��û�з��֡�\n",me);  
			return;
		}
		message_vision("��������һ����$N�ĸ��ƺ�������һ���������ϡ�\n", me);
	    tell_object(me, "��ͷһ����������¶����һ�����С�\n");
	    if(!objectp(box)) {
	         box = new(__DIR__"obj/box");
	         box->move(this_object());
			 set("already",1);
	    }
	}
	else
		tell_object(me,"���ڵ��Ͽ��ҵ����������������������̫���ˣ�ʲôҲû���ҵ���\n");
	
	return;	
}

void reset(){
	::reset();
	if (!random(8))
		set("already",0);
}
