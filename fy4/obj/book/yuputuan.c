 inherit ITEM;
void create()
{
        set_name("������", ({ "yuputuan" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                	set("no_split",1);
                set("long",
"                        
  ,,,,,,,,,;,  ,,,;;,,,,,;;,;,;,,,,,,,,,,,;,
      ;;        , ''    ,;' , ;;     ;,  ;;
      ;;         ;;,'''';;'';';; ,,,,;;,,;;
   ,,,;;,,;,   ', '  ;;';;';;';;   ,;;;  ;;
      ;; ,      ';'  ;;,;;,;; ;;  ;' ;;  ;;
      ;;  ;,      ,' ;; ;; ;; ;;,'   ;;  ;;
      ;;  '  , ,;;'  ;;';;';; ;;   '';'  ;;
'''''''''''''''';    ;' ;',;' ;'''''''''';'
\n"                );
                set("value", 200);
                set("material", "paper");
                set("desc_ext","��������");
        }
        ::init_item();
}
void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
        int sena;
        int cps;
        string book;
        me = this_player();
        cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("ָ���ʽ��study <��> <������>\n");
        if( (string) book != "yuputuan")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("��Ҫ��ʲ�᣿\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "����ϲ����ط�����" + ob->name()
                + "��\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "����һҳ" + ob->name()
                + "��̧��ͷ��ɫ���������������µĴ������㡣\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "�ɿ�ط�����" + ob->name()
                + "����ž����һ����һ�ο�ˮ�������ϡ�\n", environment(me), me);
                        break;
        }
                write("
                    ���µ�һ����С˵ 
                      �������š� 
                      һ������������
\n");
        if( cps >20 )
        {       write("��Խ��Խ���������\n");
                return 1;
        }
        if( cps >15)
        {       write("��е�ȫ���ȣ�Խ��Խ���������\n");
                return 1;
        }
                write("��е�һ�������ӵ���ֱ�����𣮣���\n");
                me->unconcious();
                return 1; 
}    
