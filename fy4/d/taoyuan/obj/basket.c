inherit ITEM;

void create()
{
   set_name("������", ({ "basket" , "������", "С����"}) );
   set_weight(500);
   set_max_encumbrance(4000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "һ����������ɵ��������������ѱ�ĥ�ķ��⡣ \n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


