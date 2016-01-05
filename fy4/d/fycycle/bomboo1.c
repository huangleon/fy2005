inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һƬ���֡����������ɸߵ����ӣ���ס��ͷ������գ��ܲ�͸�⡣
��������һ����ֵ��������������������������ţ����Ѿ���������ʱ��
�����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"bomboo2",
	"east"  : __DIR__"bomboo2",
	"north" : __DIR__"bomboo2",
	"west"  : __DIR__"bomboo2",
]));
        set("item_desc", ([
                "bamboo": "һƬ�����ƺ������ƿ���push����\n",
                "����": "һƬ�����ƺ������ƿ���push����\n",
       ]) );
        set("outdoors", "fengyun");
	set("coor/x",-40);
	set("coor/y",440);
	set("coor/z",0);

        setup();
}
void init()
{
	add_action("do_push","push");
	add_action("do_pick","pick");
	add_action("do_listen","listen");
}

int do_listen(){
	tell_object(this_player(),"�����������ƺ��е��������������ƿ�֮����\n");
	if ( QUESTS_D->verify_quest(this_player(),"��������"))
		QUESTS_D->special_reward(this_player(),"��������");
	return 1;
}

int do_pick(string arg)
{
	object bamboo;
	if ( !arg && arg != "bamboo" && arg != "����" )
		return notify_fail("��Ҫ��ʲô��\n");
	if((int) query("picked") <= 3)
	{
		write("������һ����������ӣ�С�ĵķ��ڻ��\n");
		bamboo = new("/d/taoyuan/obj/bamboo");
		bamboo->move(this_player());
		add("picked",1);
		return 1;
	}
	else
        write("�����Ѿ������۹��ˣ���\n");
        return 1;
}

int do_push(string arg)
{
    object me;
    if(!arg || arg==""){
        write("��Ҫ��ʲô��\n");
        return 1;
    }
    if( arg == "bamboo" || arg == "����" || arg == "����"){
	    me = this_player();
	    me->perform_busy(1);
	    message_vision("$N�������ƿ����ӡ�\n", me);
	        
	    if(me->query("marks/÷ɽ��") && !query("exits/northeast")) {
	    	message_vision("$N�������������ܲ쿴��һ�������ֶ�������������ƺ����˾���������\n", me);
	    	set("exits/northeast", __DIR__"meilin");
	    	call_out("close_path", 5);
	    } else if( !query("exits/southwest") ) {
		    message_vision("�������ȥ��¶��һ��ͨ�����Ϸ����С������\n", me);
		    set("exits/southwest", __DIR__"bomboo");
		    call_out("close_path", 10);
    	}
    	return 1;
    } else {
        write("�㲻������"+arg+"\n");
        return 1;
    }
}


void close_path()
{
    if( query("exits/southwest") ) {
	    message("vision", "���ӵ��˻�������ס��ȥ·��\n", this_object() );
    	delete("exits/southwest");
	} else if( query("exits/northeast") ) {
		message("vision", "���ӵ��˻�������ס��ȥ·��\n", this_object() );
		delete("exits/northeast");
	}
}

