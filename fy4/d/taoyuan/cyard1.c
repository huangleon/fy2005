inherit __DIR__"no_killing_place";
void create()
{
	set("short", "СԺ");
    set("long", @LONG
�ֱ۴�ϸ�������ٱ����ӳ���һ��Ƭ��һ������С�������ñ����ɣ����Ƶ�
����бб���������棬���ӵľ�Ө��͸�����Ѽ�����һ��ˮ����ˮ������һ��ľͷ
��ꤣ�ҡ������������ѽѽ��������
LONG
        );
	set("exits", ([ 
		"east" : __DIR__"cyard",
	]) );
	
	set("item_desc", ([
		"������" : "������������¹�����һ������С���ѡ�\n",
		"grape vine" : "������������¹�����һ������С���ѡ�\n",
	]) );
	set("grape_amount", 5);
    	set("no_magic", 1);
    	set("outdoors","taoyuan");
	set("coor/x",15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}


void init()
{
	::init();
	add_action("do_pick", "pick");
    	add_action("do_look", "look");
    	add_action("do_approach", "approach");
}

int do_pick(string arg)
{
    object me, grape;

   	me = this_player(); 
   	if(!arg || arg != "grape" && arg != "����") return 0;	
   	if ((int) query ("grape_amount") >= 0)
   	{
  		grape = new(__DIR__"obj/grape");
      	grape->move(me);
      	add("grape_amount", -1);
      	message_vision("\n$N����ժ��һ������������\n", me);
   	} else { 
      write ("���Ѷ���ժ���������� \n");
    }
      return 1;
}

int do_look(string arg)
{
	object me;
	object room;
	me = this_player();
	if(!arg)	return 0;
	
	if (arg != "��" && arg != "well" && arg != "ˮ��") return 0;
	
	switch ( random (2)) {
		case 0:
			tell_object(me,"ˮ������ʪ�����ģ���������˴��ˮ�����ǲ�Ҫ������������裩��̫����\n"); 
			break;
		case 1:
			message_vision("$N̽ͷ��ˮ������ȥ�� \n", me); 
			tell_object(me,"�ڲ�¡�˵�ˮ������ס� \n");
                break;
	}
        return 1;
}

int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "��" && arg != "well" ) return 0;
	switch ( random (3)) {
		case 0:
message_vision("$N�߽�ˮ��̽ͷ������ȥ�� \n", me); 
tell_object(me,"ˮ������ף��������ƺ���������������ˮ�������� \n");
                break;
		case 1:
message_vision("$N�߽�ˮ��̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me); 
message_vision("$N��ͷײ�ھ����ϣ�һ���ӻ��˹�ȥ��\n", me);
		me->unconcious();
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
		case 2:
message_vision("$N�߽�ˮ��̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me); 
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
	}

        return 1;
}

void reset(){
	::reset();
	set("grape_amount", 5);
}
