inherit ROOM;

void create()
{
        set("short", "��ɼ����");
        set("long", @LONG
���������ʸ���һ����ɼ���ϣ���Ҷ���ܣ�����������Ҳ͸����ï�ܵ����ڡ�
��������Ժ�������������µ�һ�ж������������˷������ƺ��Ǹ���͵������
�����ĺõط������ںܴ�һ������֦���������˸�����Ժ���
LONG
        );
        set("objects", ([
                __DIR__"npc/banditspy" : 1,
		]) );

		set("item_desc", ([
			"����":		"���ںܴ�һ������֦���������˸�����Ժ���\n",
			"��֦":		"һ������֦���������˸�����Ժ���\n",
			"Ժ��":		"��ɼ���Ķ��Ͻ��и�Ժ�ӣ�����֦�Ͽ�������ȥ��\n",
			"branch":	"һ������֦���������˸�����Ժ���\n",
		]));
				
        set("exits", ([ /* sizeof() == 2 */
  			"down" : __DIR__"groad3",
		]));

        set("coor/x",80);
	set("coor/y",90);
	set("coor/z",10);
	set("map","eren");
	setup();

}

void init()
{
	add_action("do_jump", "jump");
}


int do_jump(string arg)
{
   	object me, room;
   	me = this_player();
   	
   	if(!arg || (arg != "down" && arg!="Ժ��" && arg!="��֦" && arg!="branch")) {
   		tell_object(me,"��Ҫ���Ķ�����\n");
   		return 1;
   	}
   	
   	if (me->is_busy()|| me->is_fighting()) {
   		tell_object(me,"��������æ��\n");
   		return 1;
   	}
   		
   	message_vision("$N�����ϰ������˳����֦����һ�»�����Ժ���\n\n", me);
   	room = find_object(__DIR__"backyard"); 
   	if(!objectp(room)) room=load_object(__DIR__"backyard");
    me->move(room);
    message("vision",me->name()+"��ƮƮ���䵽��Ժ�ڡ�\n", environment(me), me); 
   	return 1;
}