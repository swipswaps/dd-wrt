/*
 * Use at your own risk.
 *
 * Copyright (C) 2005-2008 Sourcefire, Inc.
 * 
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>
 */


#include "sf_snort_plugin_api.h"
#include "sf_snort_packet.h"
#include <ctype.h>

//#define DEBUG
#ifdef DEBUG
#define DEBUG_WRAP(code) code
#else
#define DEBUG_WRAP(code)
#endif

/* declare detection functions */
int rule15125eval(void *p);

// Keeps track of number of /dp(end)group tags
typedef struct {
   int groupTally;
} dpgroupcount;

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
/* flow:established, to_client; */
static FlowFlags rule15125flow0 = 
{
    FLOW_ESTABLISHED|FLOW_TO_CLIENT|FLOW_ONLY_REASSMBLED /*XXX This would be ideal. wtf?*/
};

static RuleOption rule15125option0 =
{
    OPTION_TYPE_FLOWFLAGS,
    {
        &rule15125flow0
    }
};
// content:"|5C|dp"; 
static ContentInfo rule15125content1 = 
{
    (uint8_t *) "|5C|dp", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule15125option1 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule15125content1
    }
};
// content:"group", depth 8, relative; 
static ContentInfo rule15125content2 = 
{
    (uint8_t *) "group", /* pattern (now in snort content format) */
    8, /* depth */
    0, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED|CONTENT_FAST_PATTERN, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule15125option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule15125content2
    }
};
// content:"group", depth 5, relative; 
static ContentInfo rule15125content3 = 
{
    (uint8_t *) "pgroup", /* pattern (now in snort content format) */
    6, /* depth */
    0, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule15125option3 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule15125content3
    }
};
// content:"endgroup", depth 8, relative; 
static ContentInfo rule15125content4 = 
{
    (uint8_t *) "pendgroup", /* pattern (now in snort content format) */
    9, /* depth */
    0, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule15125option4 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule15125content4
    }
};
// content:"|5C|do", relative; 
static ContentInfo rule15125content5 = 
{
    (uint8_t *) "|5C|d", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule15125option5 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule15125content5
    }
};
/* references for sid 15125 */
/* reference: cve "2008-4030"; */
static RuleReference rule15125ref1 = 
{
    "cve", /* type */
    "2008-4030" /* value */
};

/* reference: url "technet.microsoft.com/en-us/security/bulletin/MS08-072"; */
static RuleReference rule15125ref2 = 
{
    "url", /* type */
    "technet.microsoft.com/en-us/security/bulletin/MS08-072" /* value */
};

static RuleReference *rule15125refs[] =
{
    &rule15125ref1,
    &rule15125ref2,
    NULL
};
/* metadata for sid 15125 */
/* metadata:service http, policy balanced-ips drop, policy security-ips drop; */
static RuleMetaData rule15125service1 = 
{
    "service http"
};


//static RuleMetaData rule15125policy1 = 
//{
//    "policy balanced-ips drop"
//};
//
//static RuleMetaData rule15125policy2 = 
//{
//    "policy security-ips drop"
//};

static RuleMetaData rule15125policy3 = 
{
    "policy max-detect-ips drop"
};

static RuleMetaData *rule15125metadata[] =
{
    &rule15125service1,
//    &rule15125policy1,
//    &rule15125policy2,
    &rule15125policy3,
    NULL
};
RuleOption *rule15125options[] =
{
    &rule15125option0,
    &rule15125option1,
    &rule15125option2,
    &rule15125option3,
    &rule15125option4,
    &rule15125option5,
    NULL
};

Rule rule15125 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "$HTTP_PORTS", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       15125, /* sigid */
       12, /* revision */
   
       "attempted-user", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "FILE-OFFICE Microsoft Word rich text file unpaired dpendgroup exploit attempt",     /* message */
       rule15125refs /* ptr to references */
       ,rule15125metadata
   },
   rule15125options, /* ptr to rule options */
   &rule15125eval, /* use the built in detection function */
   0 /* am I initialized yet? */
};


/* detection functions */
int rule15125eval(void *p) {
    
   const uint8_t *cursor_normal = 0;
   SFSnortPacket *sp = (SFSnortPacket *) p;

   const uint8_t *end_of_payload;

   dpgroupcount *dpCount;

   DEBUG_WRAP(printf("rule15125eval enter\n"));

   if((sp == NULL) || (sp->stream_session_ptr == NULL))
      return RULE_NOMATCH;

   if(sp->payload == NULL)
      return RULE_NOMATCH;
    
   // flow:established, to_client;
   if(checkFlow(p, rule15125options[0]->option_u.flowFlags) <= 0)
      return RULE_NOMATCH;

   DEBUG_WRAP(printf("rule15125eval flow match\n"));

   // Since "group" is in the fast pattern matcher, we want to quickly make sure
   // that either \dpgroup or \dpendgroup is in the packet so we can drop out
   // before getting into the more intense detection algorithm.
   
   // content:"|5C|dp", nocase;
   if(contentMatch(p, rule15125options[1]->option_u.content, &cursor_normal) > 0) {
      // content:"group", depth 8, nocase, relative;
      if(contentMatch(p, rule15125options[2]->option_u.content, &cursor_normal) <= 0)
         return RULE_NOMATCH;
   }

   // Get-store-initialize session data
   dpCount = (dpgroupcount *)getRuleData(sp, (uint32_t)rule15125.info.sigID);

   if(!dpCount) {
      dpCount = (dpgroupcount *)allocRuleData(sizeof(dpgroupcount));
      if (dpCount == NULL)
         return RULE_NOMATCH;

      if(storeRuleData(sp, dpCount, rule15125.info.sigID, &freeRuleData) < 0)
      {
         freeRuleData(dpCount);
         return RULE_NOMATCH;
      }

      dpCount->groupTally = 0;
   }

   DEBUG_WRAP(printf("rule15125eval dpCount=0x%p\n", (void*)dpCount));

   // Reset cursor to beginning of payload
   if(getBuffer(sp, CONTENT_BUF_NORMALIZED, &cursor_normal, &end_of_payload) <= 0)
      return RULE_NOMATCH;

   // Main matching loop for "|5C|d"
   while(contentMatch(p, rule15125options[5]->option_u.content, &cursor_normal) > 0) {

      if(cursor_normal + 2 >= end_of_payload)
         return RULE_NOMATCH;
             
      // If entering a /do statement, reset counter
      if(*cursor_normal == 'o') {

         if(!isalnum(*(cursor_normal+1))) {
            dpCount->groupTally = 0;
         }

      // Match on "pgroup" within 6 then increment count
      } else if(contentMatch(p, rule15125options[3]->option_u.content, &cursor_normal) > 0) {

         dpCount->groupTally++;

      // Match on "pendgroup" within 9 then decrement count; fire if count is ever negative
      } else if(contentMatch(p, rule15125options[4]->option_u.content, &cursor_normal) > 0) {

         dpCount->groupTally--;

         if(dpCount->groupTally < 0)
            return RULE_MATCH;

      }

      DEBUG_WRAP(printf("rule15125eval dpCount->groupTally=%d\n", dpCount->groupTally));
   }

   return RULE_NOMATCH;
}

/*
Rule *rules[] = {
    &rule15125,
    NULL
};
*/

