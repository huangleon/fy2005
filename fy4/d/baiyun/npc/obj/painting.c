#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
    set_name("�����轣ͼ", ({ "painting" }) );
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�������õĻ����轣ͼ��ī���ƺ���δ�о�����������������һ����Ů�����ᱦ������Ц�������½�·�������������������Ц����Ȼ��\n");
		set("material", "paper");
		set("no_give",1);
		set("annie/by_hy_draw",1);
	}
    ::init_staff(1);

    set("wield_msg", "$N��$n���һ�������������衣\n");


}
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
