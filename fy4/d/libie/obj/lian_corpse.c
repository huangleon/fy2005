inherit ITEM;

void create()
{
        set_name("���õ�ʬ��", ({ "corpse" }) );
        set("long", "
����һ��Ů�ӵ�ʬ�ǣ��䲻�Ǻ�Ư����������ȥ������ʵ�����˰����ľ�
����Ů����������˫ĿԲ�����գ�˫ȭ���ա�\n");
        set("unit", "��" );
        set("no_get", 1);
        set("cloth",1);
}


int 	init()
{
	add_action("do_look","look");
}


int do_look(string arg)
{
	object me;
	object cloth;
	me = this_player();
	if(!arg)	return 0;
	
	if (arg != "˫ȭ" && arg != "��" && arg != "hand" && arg!="fist") return 0;
	
	if (!query("cloth"))
	{
		tell_object(me,"�������������ý��յ�˫�֣�����ʲôҲû�С�\n");
		return 1;
	}
	
	tell_object(me,"�������������ý��յ�˫�֣�������һƬ�鲼��ɫ���ʺ졣\n");
	cloth = new("/d/libie/obj/cloth");
	if (!cloth->move(me))
		cloth->move(environment(me));
	set("cloth",0);
	return 1;
}