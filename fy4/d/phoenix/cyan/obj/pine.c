
inherit ITEM;

void create()
{
	set_name("����", ({"tree"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�øߴ���������ڳ��㺣�ϣ��������и���ڵ�����������·���ʲô�ڿ�̽���㡣\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


void 	init()
{
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="��")) 
		return notify_fail("������ʲô��\n");;
	message_vision("$Nץ�������������˰��죬һ�����ֵ���������\n",me);
	tell_object(me,"˵�㲻�У���Ͳ��У���Ҳ���У��������С�\n");
	return 1;
}
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
