#include <ansi.h> 
inherit NPC;

int do_tatoo(string arg);
int ask_tatoo();

void create()
{
    set_name("��ѩ", ({"hex"}));
    set("long","
��ѩ������û�������Ҳû��֪������һ��Ư��С����ƾʲô�ܰ���ȫȫ
�����߽�������ͽ���ӣ���Ʀ��å���ƺ����ԹԵ�����ԶԶ�ģ�Ҳ������
�������������糤�����롣��ѩ������ļ��գ�Ҳ��Զ��С�������ģ���
���������ĳ���������Ը���ƣ���ʲô��ʲô����ô�õ����գ���Ȼ�۸�
Ҳ���ƣ���Ҫ�Ǹ���Ȥ������������������������Կ���
\n\n");
        set("gender","Ů��");
      set("title", CYN"С��Ѿ ���ķ�"NOR);
        set("age",18);
        set("agi",50);
        set("str",20);
        set("per",50);        
        set("NO_KILL",1);
        set("combat_exp", 100);
        set("attitude", "friendly");        
        set("chat_chance", 1);
        set("chat_msg", ({
             (: random_move :),
         }) );  
        set("inquiry", ([       
                "����":     (: ask_tatoo :),
                "tatoo":    (: ask_tatoo :),    
         ]));
        setup();
        carry_object("/obj/armor/cloth",
              (["name": MAG"��ɫ��ɴ"NOR,
     ]))->wear();  
        carry_object("/d/qianfo/npc/obj/needle",
              (["name": BLK"���糤������"NOR,
                "value": 0,
     ]))->wield();       
}
 
void init(){
add_action("do_tatoo","tatoo");
::init();
}

int ask_tatoo()
{
  object me;
me = this_player();
if (me->query("gender") == "Ů��") {
  tell_object(me,CYN"��ѩ���Ŵ��۾������㣺��λ�������Щʲô��ֻҪ����˵��tatoo <����>�����Ҷ��ܰ����ơ�\nһ�㶼���ۡ��������ôƯ�������˵㣬һ���ƽ�ͺ��ˡ�\n"NOR);
}else{
tell_object(me,CYN"��ѩ����ԥԥ�ض�����һ�ᣬ˵������λ��������Щʲô���ö������˺���˵һ����tatoo <����>����\n�۸���һ���ƽ𣬲�����������Ů���ܲ��ף��鷳�����Ǳ���Щ���εĵط�\n"NOR);
  }
  return 1;
}

int do_tatoo(string arg)
{
object me;
me = this_player();

  if( !arg ) {
    return notify_fail(CYN"ָ���ʽ : tatoo <����>\n"NOR);
   }
   
  if( strlen(arg) > 40 ) {
    ccommand("lazy");
    return notify_fail(CYN"��ѩ���˸���Ƿ����Ҫ�Ƶ�̫�鷳�ˡ�\n"NOR);
   }   
   
  if (me->query("deposit")<10000)
    return notify_fail("��Ĵ���һ���ƽ�\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        me->set_temp("body_print", arg + NOR);
        me->add("deposit",-10000);
   tell_object(me,CYN"��ѩ���˲�ͷ�ϵĺ����������������������ۣ�����������Щ��ʱ������ѱ����ᵭȥ��\n"NOR);

  return 1;
}
