
inherit ITEM;

void create()
{
        set_name("�ײ�", ({ "coffin"}) );
        set_weight(500); 
	set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("unit", "��");
                set("long", "����һ�ߺ���ͨ����ľ�ײģ��׸��ƺ���δ���ϡ�\n");
                set("value", 1);
        }
}
int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object cps;
    if(!arg="coffin"||!arg="�׸�") return 0;
        message_vision("$N�ƿ��ײĵĸ���...\n",this_player());
    tell_object(this_player(),"�㷢��һ��Ů�ӵ�ʬ�ǣ��䲻�Ǻ�Ư����������ȥ������ʵ��\n���˰����ľ�����Ů����������˫ĿԲ�����ա�\n");
    if(present("corpse",this_object())) return 1;
    cps=new(__DIR__"lian_corpse");
    cps->move(this_object());
    return 1;
}
