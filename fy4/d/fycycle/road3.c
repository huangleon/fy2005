inherit ROOM;
string bank();
void create()
{
        set("short", "�Ǳ�С·");
        set("long", @LONG
����������С·�����������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ��
���Ǹߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ���
���̲ݡ�΢�������һ�ɵ���������Ϣ�����߾��Ƿ��Ƴǵĸ����ϱ������������
һ��Ƭï�ܵ�����С�����������ļ�����˵�����������ֺ����Ƿ紵��Ҷ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north":__DIR__"bomboo",
  "east" : __DIR__"fynorth",
  "southwest" : __DIR__"road2",
]));
	set("item_desc", ([
		"�ӵ�" : (: bank :),
		"bank" : (: bank :),
		"�̲�" : (: bank :),
		"grass" : (: bank :),
		]));
        set("outdoors", "fengyun");
	set("coor/x",-60);
	set("coor/y",320);
	set("coor/z",0);

        setup();
}

string bank(){
	object me;
	me = this_player();
	tell_object(me, "��ע�⵽�ӵ�����һ���̲���ɫ����ΧҪǳ���ƺ��������˲ȹ���\n");
	tell_object(me, "��Ҳ�����ȥ�Ȳȿ�����stamp��\n");
	add_action("do_stamp", "stamp");
	return "";
}

int do_stamp(string arg){
	object me, room;
	me = this_player();
	if(!arg || (arg != "grass" && arg != "�̲�")){
		return notify_fail("��Ҫ��ʲô��\n");
	}
        message_vision("$NС��������ߵ��ݵ��ϣ��Ĵ����˲ȡ�\n", me);
		if (!REWARD_D->check_m_success( me,"��̽����"))
			return notify_fail("����ý��µ���������ز���ȥ�������\n");
		
		message_vision("ֻ����֨֨һ�������ʶ���������$N���µĲݵ�ͻȻ¶����һ�����ϵĶ��ڡ�\n", me);
		message_vision("$N������һ���������˶��У��ݵ���$N�����������Ϣ�غ����ˡ�\n\n",me);
		room = find_object("/d/cave/yd");
		if(!objectp(room)){
            room = load_object("/d/cave/yd");
		}
		me->move("/d/cave/yd");
		return 1;	
}
