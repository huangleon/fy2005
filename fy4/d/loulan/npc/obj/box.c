inherit ITEM;
string box();

void create()
{
        set_name("��ľ�����", ({ "woodcase"}) );
        set_weight(50000); 
	set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("unit", "��");
                set("long", (: box() :));
                set("value", 1);
                set("closed",1);
        }
	::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
	add_action("do_look","look");	 
}

int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "woodcase" ) return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N����֨��һ������$n���ˡ�����\n", me, ob);
		ob->set("closed",0);
        return 1;
}

int	do_look(string arg) {
	if (!arg || (arg != "woodcase"  && arg!= "��ľ�����"))
		return 0;
		
	if (query("closed"))
		write( "
    һ�ڼ�Ϊ������ľ����䣬��ֻ���ϣ������Żƽ�����Ҳ�ǻƽ�
�ġ�������������ȴδ���ϡ�\n");
	else
		write("
    һ�ڼ�Ϊ������ľ����䣬��ֻ���ϣ������Żƽ�����Ҳ�ǻƽ�
�ġ�������������ȴδ���ϡ�
    ��������װ�ľ��Ǹ����ˡ�һ����������ȫ�����Ů�ˣ���Ů�Ӱ���
������������������������������ô��ͣ���������ô������������
��ô��Ө�������Ż���΢΢����ţ����۾�ȴ�Ǳ��ŵģ�����������ȴ��
���Σ������ڳ�˯�У����������Բ��ѡ�
	\n");
	return 1;
}