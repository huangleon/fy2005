//XXDER
inherit ITEM;
void create()
{
   set_name("����ƿ", ({ "yu ping", "bottle", "��ƿ" }) );
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "һ�������������ɵ�Сƿ�ӡ�\n");
      set("value", 0);
   }
    ::init_item();
}

int is_container() { return 1; }
