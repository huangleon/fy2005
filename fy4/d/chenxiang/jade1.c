// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
    set_name("����", ({ "round jade"}) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ����������ĥ�ɵ��񻡣���Լ�а˴������֮һ԰��\n");
        set("unit", "��");
        set("value", 1000);
        set("wear_msg", "$N��һ��$n����ͷ�ϡ�\n");
        set("unwield_msg", "$N��$n��ͷ�ϳ���������\n");
        set("female_only", 1);
        set("need_fix",1);
    }
	::init_head();
}

void init()
{
    //if(this_player()==environment() && query("fixed"))
    add_action("do_combine","combine");
}

int do_combine()
{
    object me;
    object *inv;
    object ob;
    int i,sum=0;
    me = this_player(); 
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("id") == "round jade" && inv[i]->query("fixed"))  
            sum=sum+1;
   
    if(sum==3)
    {
        if (!me->query_temp("marks/��ʯ��")) {
        	tell_object(me,"���������ƺ�����Ϊ�㶨���ģ�ƴ��������\n");
        	return 1;
        }	
        tell_object(me,"�㽫���е��������񻡺ϲ���һ�����ס�\n");
        ob=new(__DIR__"botao");
        ob->set("armor_prop/jade_pro",1);
        ob->move(me);
        for(i=0; i<sizeof(inv); i++)
            if(inv[i]->query("id") == "round jade" && inv[i] != this_object())
                destruct(inv[i]);
        destruct(this_object());
        return 1; 
    }
    return 0;
}
