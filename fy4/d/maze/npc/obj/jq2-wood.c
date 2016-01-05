#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"�޼�ľ"NOR, ({"wood vessel","vessel"}) );
	set_weight(500);
	set_max_encumbrance(500);	
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", "
һ����̵�̴ľС��������ɢ���ŷ��㣬����԰Ѻ��ʵ�ҩ�ݷ��ڶ���
���ƣ�lian����\n\n");
		set("value", 1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_give",1);
		set("prep","in");
	}
        ::init_item();
}


void init()
{
	if(this_player()==environment())
		 add_action("do_lian","lian");
}

int do_lian(string lian)
{
	object	me, *inv, *ob;
        int     i, n;
	string  *ob_name = ({GRN"���Ĳ�"NOR,MAG"�ݸλ�"NOR,BLU"���Ҷ"NOR,HIR"�߾�֦"NOR });
	        
        ob = allocate(4);
        me = this_player();
        inv = all_inventory(me);
                
        if (me->is_busy())
        	return notify_fail("��������æ��\n");
                	
        for (i=0; i<4; i++) {
        	n = sizeof (inv);
        	while (n--) {
        		if (inv[n]->query("name") == ob_name[i] && inv[n]->query("wujian")) 
        			ob[i] = inv[n];
         	}
         	if (!objectp(ob[i])) {
        		tell_object(me, "��ȱ��"+ob_name[i]+"��\n");
        		return 1;
        	}
        }
        
        if (environment(me)->query("short")!= "�޼���")
        	return notify_fail("�޼�ľ��ֻ�����޼��õ�¯���Է���ʹ�á�\n"); 
        
        
        message_vision(HIC"
$N�����Ĳݡ��ݸλ������Ҷ���߾�֦һһͶ���޼�ľ����

ͻȻ�������޼�ľ����þ�Ө͸����һ�������Զ����������𣬷·�
ʶ��$Nһ�㣬����$N�Ŀڱ�֮�С� 

\n"NOR, me);
	tell_object(me, YEL"
��پ�����·���̥����һ�㣬�ζ�������Ȼ���裬�����ᶥ������֮�г��� 
����֮������ü�������Ҳ��Ȼ��ȥ������ 

�㲻�����±�ϥ���š�\n\n"NOR,me);

	me->start_busy(100);
	destruct(ob[0]);
	destruct(ob[1]);
	destruct(ob[2]);
	destruct(ob[3]);

	
	environment(me)->event3(me, 0);
	destruct(this_object());

	return 1;
}