inherit ITEM;
inherit F_LIQUID;

void create()
{
   	set_name("С���", ({ "fish tank" , "fishtank", "yugang"}) );
   	set_weight(300);
   	set_max_encumbrance(200);
   	if( clonep() )
    	set_default_object(__FILE__);
   	else {
    	set("prep", "in");
      	set("unit", "��");
      	set("long", "��ײ���ȴʮ�־��£���ɫ�Ĵ����Ͼ��ȵز���ϸ������ƣ�
������кɻ���ͼ���� \n");
      	set("value", 100);
   		set("marks/haswater", 0);
   }
    ::init_item();
}

int is_container() { return 1; }

void init() {
	add_action("do_fill", "fill");
}

int do_fill(string arg)
{
    string name, type, container;
    
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
    	return notify_fail("����һ��������û����ɡ�\n");
    if( !environment(this_player())->query("resource/water") )
    	return notify_fail("����û�еط�����װˮ��\n");
	if(query("marks/haswater")) {
		tell_object(this_player(),"������Ѿ�װ��ˮ��ѽ��\n");
		return 1;
	} else {
		message_vision("$N��������" + name() + "��װ����ˮ��\n", this_player());
		set("marks/haswater", 1);
		set("long", "С�����װ�˴���ˮ���ɻ���ͼ����ˮ����ӳ�����Ե�����������\n");
		set_weight(1000);
	}
    return 1;
}
