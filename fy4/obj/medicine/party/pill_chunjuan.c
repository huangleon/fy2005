inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(YEL"����"NOR , ({ "chun juan" }) );
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"�����Բ�α���Ƥ������ģ��ɳ����Σ�Ȼ�����͹�ը�����ɫ������ɡ�\n"NOR);
        	set("unit", "ֻ");
        	set("lore",1);
        	set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff1,buff2;
	object me = this_player();
	string bufftype,type,name,msg;
	int amount,n,n2;
	
  string *list = ({ "apply/karma","apply/composure","apply/agility","apply/strength" });
  string *typelist = ({ "karup" , "cpsup" , "agiup" , "strup" });
  int  *list_m = ({ 10, 10, 10, 10 });
  string *list_c = ( {"����","����","�ٶ�","����" });
  string *list_c_n = ( {"��","��","��","��" });

	msg = HIY "$N��ʱ���û���ů�⣺�������Ҹ���\n"NOR;
	
	if (ANNIE_D->check_buff(me,"karup") || ANNIE_D->check_buff(me,"cpsup") || ANNIE_D->check_buff(me,"agiup") || ANNIE_D->check_buff(me,"strup"))	// it won't show up..just eat it.
		return notify_fail("��ζ���档\n"); 
	
  n = random(sizeof(list));
  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];
  
	buff1 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"����"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":msg,
		//"disa_msg": "",
		//"special_func":1,
	]);
  ANNIE_D->buffup(buff1);      
  tell_object(me,CYN"�����"+ list_c[n] + "�����"+ amount + "�㣩\n"NOR);
    
  n2=n;
  
  while(n2==n) {
  	n = random(sizeof(list));
  }

  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];


  buff2 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"����"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
	]);
  ANNIE_D->buffup(buff2);      
  tell_object(me,CYN"�����"+ list_c[n] + "�����"+ amount + "�㣩\n"NOR);

  destruct(this_object());
 	return 1;
}
