//XXDER
inherit ITEM;
void create()
{
   set_name("����", ({ "silk bag", "����"}) );
   set_weight(50);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("long", "����һ�����µĽ��ҡ�\n");
      set("value", 100);
   }
}

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   if( arg != "silk bag" ) return 0;
   tell_object(this_player(),"�꿪����֮ʱ�����ɥ�ڰ�����֮�֣���ȥ����֮����
Ѱ��ɫ�����������ų��ϣ������ִ˻���\n");
   return 1;
}
