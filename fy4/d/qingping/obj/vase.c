//XXDER

inherit ITEM;
void create()
{
   set_name("����ƿ", ({ "vase" , "white vase", "��ƿ" }) );
   set("no_shown", 1);
   set("no_get",1);
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "����һ������ƿ��ͨ������覡�\n");
      set("value", 2000);
   }
}
int is_container() { return 1; }
